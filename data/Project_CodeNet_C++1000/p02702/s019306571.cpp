#include<bits/stdc++.h>
#define loop(start,i,end) for(i = start; i <= end; i++)
#define debug(x) cout << #x << " : " << x << "\n"
#define inf 1000000005
#define ll long long
#define type long long
#define mod 2019
#define nmax 200005
using namespace std;

ifstream in("multiple2.in");
ofstream out("multiple2.out");

//void debug_m(type x[nmax][nmax], type n , type m, string nume){ll i,j; cout << nume << " : \n";;for (i = 1; i <= n; i++) {for (j = 1; j <= m; j++) cout << x[i][j] << " ";cout << "\n";}cout << "\n";}
void debug_a(type x[nmax], type n , string nume){type i;cout << nume << " : ";for (i = 1; i <= n; i++)cout << x[i] << " ";cout << "\n";}
void debug_v(vector<type> &v , string name){cout << name << " : ";for (auto k : v) cout << k << " ";cout << "\n";}

string s;
ll a[nmax],n,v[nmax],f[nmax];
int main()
{ll i,put10,sol = 0;
    cin >> s;
 //   cout << "s : " << s << "\n";
    for (i = 0; i < s.size(); i++) a[i + 1] = s[i] - '0';
    n = s.size();

  //  debug_a(a , n , "a_original");

    put10 = 1;
    for (i = n; i >= 1; i--) {
        a[i] = a[i] * put10 % mod;
        put10 = put10 * 10 % mod;
    }

    for (i = 1; i <= n; i++)
        v[i] = ( a[i] + v[i - 1] ) % mod;

   // debug_a(a , n , "a_nou");
   // debug_a(v , n , "v");

    for (i = 1; i <= n; i++){
        f[v[i]]++;
    }

    f[0]++;

    for (i = 0; i < mod; i++)
        if (f[i] > 0) {
            sol = sol + f[i] * (f[i] - 1) / 2;
            f[i] = 0;
        }
    cout << sol << "\n";
}

