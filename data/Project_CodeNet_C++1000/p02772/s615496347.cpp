 /*

                   بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
                  لآ اِلَهَ اِلّا اللّهُ مُحَمَّدٌ رَسُوُل اللّهِ
*/

/*
    Auther:   n0oO0o0Ob(None of them)
    from  :   https://n0oo0o0ob.sleek.page/

*/




#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define pb push_back

                                        #define noob n0oO0o0Ob
// ---------------------------------
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;
//----------------------------------
const ld PI = acos((ld)-1);
const int MOD = 1000000007;
//----------------------------------


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int a;
    cin >> a;
    int ara[a];
    vector<int> v;
    int k = 0;
    for(int i =0; i<a; i++){
        cin >> ara[i];
        if(ara[i] % 2== 0) v.pb(ara[i]);
    }
    for(int i =0 ; i< v.size(); i++){
        if(v[i] % 3 == 0 || v[i] % 5 == 0){
            k++;
        }
    }
    if(k == v.size()) cout << "APPROVED" << endl;
    else cout << "DENIED" << endl;





	return 0;
}

