
/*
	*	Created By: 'Present_Sir'
	*	Created On: Friday 04 September 2020 11:30:23 AM IST
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
    private:
        set < string > s;
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
            
            helper(0, n, 0, "");

            for(auto i:s) cout<<i<<endl;
        }

        void helper(int cur, int n, int prev, string k){
            if(n == cur){
                cout<<k<<endl;
                //s.insert(k);
                return;
            }
            
            for(int i=0; i<=prev; ++i){
                if(i==prev)helper( cur+1, n, prev+1, k+(char)(i+'a') );
                else helper(cur+1, n, prev, k+ (char)(i+'a'));
            }
        }
};


int32_t main(){
    IOS;
    Solver S;
    S.test();
    return 0;
}

