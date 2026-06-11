#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
using ll = long long;
using namespace std;
int main(){
    int s,w;
    cin>>s>>w;
    if(s<=w){
        cout<<"unsafe";
    }
    else{
        cout<<"safe";
    }
}
