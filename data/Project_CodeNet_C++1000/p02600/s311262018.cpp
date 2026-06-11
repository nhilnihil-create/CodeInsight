/*==============================================*\
Codeforces ID:    mdshihab
                                                  |
Name:     Md. Shihabul Minhaz                     |
Study:      CSE, JKKNIU                           |
Address:  Trishal, Mymensingh, Bangladesh         |
                                                  |
 mail:   mdshihabul20171@gmail.com                |
 FB  :   fb.com/mdshihabul.minhaz.7               |
 github: Shihabulminhaz                           |
stopstalk :  mdshihab                             |
                                                  |
@uthor   Md. Shihabul Minhaz (shihab)             |
\*===============================================*/


#include<bits/stdc++.h>
using namespace std;
#define fi(a) scanf("%d",&a);
#define fli(a) scanf("%ld",&a);
#define fll(a) scanf("%lld",&a);
#define pi(a) printf("%d\n",a);
#define ppi(i,a) printf("Case %d: %d\n",i,a);
#define ll long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
void FI()
{
#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\SHIHAB\\Desktop\\input.in","r",stdin);
#endif // ONLINE_JUDGE
}

int main()
{
    fast
  //  FI(); /// skip this line for compile
    int n;
    cin >> n;
    if(n<600) cout << 8 << endl;
    else if(n<800) cout << 7 << endl;
    else if(n<1000) cout << 6 << endl;
    else if(n<1200) cout << 5 << endl;
    else if(n<1400) cout << 4 << endl;
    else if(n<1600) cout << 3 << endl;
    else if(n<1800) cout << 2 << endl;
    else cout << 1 << endl;
    return 0;
}

