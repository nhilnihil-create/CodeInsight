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
    string s;
    cin>>s;

    int len=s.size();
    string ss="",s1="";
    ss+=s[0];
    int cnt=1;
    for(int i=1; i<len; i++){
        s1+=s[i];
        if(ss!=s1){
          cnt++;
          ss=s1;
          s1="";
        }
    }
    pf("%d\n",cnt);


    return 0;
}
