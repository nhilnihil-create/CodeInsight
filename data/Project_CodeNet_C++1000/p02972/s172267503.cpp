/// إِنَّ مَعَ الْعُسْرِ يُسْرًا
/// لَا أَبْرَحُ حَتَّىٰ أَبْلُغَ

#include <bits/stdc++.h>
#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define ld  double

#define HabdModeActive ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define S second
#define F first
#define PI acos(-1)
#define MAX 5000005
#define file freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
const int N = 2e5 + 5;
int cnt [N];
int main() {
    HabdModeActive
    int n;
    cin>>n;
    int arr[n+2];
    for(int i=1 ; i<=n; i++)
    {
        cin>>arr[i];
    }
    vector<int>vec;
    for(int i=n ; i>=1  ; i--)
    {
        if(arr[i] != cnt[i]%2)
        {
            vec.push_back(i);
            cnt[i]++;
            for(ll j=1 ;j*j <= i ; j++)
            {
                if(i%j==0 && i!=j)
                {
                    cnt[j]++;
                    if(j*j != i)
                        cnt[i/j]++;
                }
            }
        }
    }
    if(cnt[1]%2 != arr[1])
        cout<<-1;
    else{
        cout<<vec.size()<<endl;
        for(auto v :vec)
            cout<<v<<" ";
    }

    return 0;
}
