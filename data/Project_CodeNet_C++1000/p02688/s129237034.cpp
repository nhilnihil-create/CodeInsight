#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,k,d,x,cnt=0;
    cin >> n >> k;
    bool a[n+1] = {false};

    for(int i=0;i<k;i++){
        cin >> d;
        for(int j=0;j<d;j++){
            cin >> x;
            a[x]=true;
        }
    }
    for(int i=1;i<n+1;i++)
        if(a[i]==false)
            cnt++;
    cout << cnt;
    return 0;
}
