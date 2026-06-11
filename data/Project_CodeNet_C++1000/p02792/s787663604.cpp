#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    vector<vector<int>> cnt(9,vector<int>(9));
    int n,f,b;cin>>n;string s;
    for(int i=1;i<=n;i++){
        s=str(i);
        f=s[0]-'0';b=s[s.size()-1]-'0';
        if(f==0||b==0)continue;
        cnt[f-1][b-1]++;
    }
    lint ans=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            ans+=cnt[i][j]*cnt[j][i];
        }
    }
    cout<<ans<<endl;
}
