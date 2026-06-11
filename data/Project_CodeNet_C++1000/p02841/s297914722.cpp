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
    FI(); /// skip this line for compile
    int m,d,a,b;
    cin >> m >> d >> a >> b;
    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12 ){
        if(d==31) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else if(m==2){
        if(d==28) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else{
        if(d==30) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}

