#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define rep(i,n)for(urs(n)i=0;i<(n);++i

int main(){
	
int a,b,c,d;

cin >> a >> b >> c >> d;

while (a>0&&c>0){
    c=c-b;
    if(c<=0){Yes(); return 0;}
    a= a-d;
    if(a<=0){No(); return 0;}

    //cout << "a;  "  << a << "c:     " << c << endl;
}
if(a>c)
Yes();
else No();

    return 0;

}