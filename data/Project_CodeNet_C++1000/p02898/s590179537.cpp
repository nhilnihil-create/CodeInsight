#include <bits/stdc++.h>
#define ii pair <int , int>
#define is pair <int, string>
#define ll long long
#define mx 100000
#define sf scanf
#define sf(n) scanf("%d",&n)
#define pf printf
using namespace std;
vector <int> v;

/*int intConvert(string s){
    int n;
    stringstream geek(s);
    geek >> n;
    return n;
}*/

/*string strConvert(int n){
    string s;
    stringstream ss;
    ss << n;
    s=ss.str();
    return s;
}*/


int main(){
    int n,k;
    sf(n),sf(k);

    int cnt=0;
    while(n--){
        int a;
        sf(a);
        if(a>=k) cnt++;
    }
    pf("%d\n",cnt);


    return 0;
}
