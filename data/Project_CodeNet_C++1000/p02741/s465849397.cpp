
/*
	*	Created By: 'Present_Sir'
	*	Created On: Friday 04 September 2020 11:10:32 AM IST
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
           int ar[] = { 1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51 };

           int n;
           cin>>n;
           cout<<ar[n-1]<<endl;
        }
};


int32_t main(){
    IOS;
    Solver S;
    S.test();
    return 0;
}

