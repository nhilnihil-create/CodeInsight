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
    string x;
    cin >> a >> x;
    int v=0;
    for(int i=0; i<a-2; i++){
        if(x[i] == 'A' && x[i+1] == 'B' && x[i+2] == 'C') v++;
    }
    cout << v << endl;



	return 0;
}

