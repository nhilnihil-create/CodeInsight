#include <bits/stdc++.h>
#define mem(i,a) memset(i,a,sizeof(i))
#define PI acos(-1.0)
#define DMAX 100000+5
#define MOD 998244353
#define eps 1e-8
#define mp make_pair
#define pb push_back
#define INF 1000000000+9
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
inline void read(int &f){
	f=0;
    ll x=1;
    char ch=getchar();
    while(ch<48 || ch>57) {
        if(ch=='-') {
            x=-1;
        }
        ch=getchar();
    }
    while(ch<=57 && ch>=48) {
        f=f*10+ch-'0';
        ch=getchar();
    }
    f*=x;
}
int n;
int main(){
    read(n);
    int p=n/200;
    switch(p){
        case 2:cout<<8<<endl; break;
        case 3:cout<<7<<endl; break;
        case 4:cout<<6<<endl; break;
        case 5:cout<<5<<endl; break;
        case 6:cout<<4<<endl; break;
        case 7:cout<<3<<endl; break;
        case 8:cout<<2<<endl; break;
        case 9:cout<<1<<endl; break;
    }   
    return 0;
}
