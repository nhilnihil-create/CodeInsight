
/*
	*	Created By: 'Present_Sir'
	*	Created On: Thursday 27 August 2020 03:01:29 PM IST
*/

#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define sz(v) ((int)v.size())
#define lgt(s) ((int)s.length())
#define int long long
using namespace std;

class Solver{
    public:
        void test(){
            //int t; cin>>t; for(int i=1; i<=t; ++i)
            {
                //cout<<"Case #"<<i<<": ";
                this->solve();
            }
        }
        void solve(){
            int n;
            cin>>n;
            map < int, int > mp;
            int N = 1e6+5;
            //cout<<N<<endl;
            vector < bool > present(N,0);
            
            for(int i=0; i<n; ++i){
                int x;
                cin>>x;
                mp[x]++;
            }
            int ans = 0;
            for(auto x: mp){
                if(present[x.first]) continue;
                if(x.second == 1)ans++;
                for(int i=x.first; i<N; i+=x.first){
                    //cout<<i<<endl;
                    present[i] = true;
                }
            }
            cout<<ans<<endl;
        }
};


int32_t main(){
    IOS;
    Solver S;
    S.test();
    return 0;
}

