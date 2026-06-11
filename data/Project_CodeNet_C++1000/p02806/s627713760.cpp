#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    int n;
    cin>>n;
    vector<string> s(n);
    vector<int> t(n);
    rep(i,0,n)cin>>s[i]>>t[i];
    string x;
    cin>>x;

    int sum=0;
    rep(i,0,n)sum+=t[i];

    rep(i,0,n){
        if(x!=s[i])sum-=t[i];
        else{
            sum-=t[i];
            break;
        }
    }
    cout<<sum<<endl;
    return 0;
}