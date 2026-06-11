#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define MOD 1000000007
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define all(v) v.begin(), v.end()
#define alla(a,n) a, a + n
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;
using namespace std;

int n;
int main() {
    //freopen("input.txt", "r", stdin) ;
    //freopen("output.txt", "w", stdout) ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL) ; cout.tie(NULL) ;
    cin>>n;
    vector<int> lists(n);
    lists.clear();
    for(int i=0;i<n;i++){
        cin>>lists[i];
    }
    int ans=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(lists[i]==lists[j] || lists[i]==lists[k] || lists[j]==lists[k]) continue;
                if(lists[i]+lists[j]>lists[k] && lists[j]+lists[k]>lists[i] && lists[i]+lists[k]>lists[j]){
                        ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}


