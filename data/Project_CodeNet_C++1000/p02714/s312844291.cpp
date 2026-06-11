#include <iostream>
#include <iomanip> //setprecision()
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
using ll = long long;
using namespace std;

int monmo(char ms){
    if(ms=='R')return 3;
    else if(ms=='G')return 2;
    else if(ms=='B')return 1;
    else cout<<ms;
    return 0;
}

int main() {
    int n;
    map<string,int> m,m2;
    string s,s2,s3,s4,s5;
    string rgb="BGR";
    ll count=0;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        s2=s[i];
        m[s2]++;
    }
    for(int i=0;i<n-2;i++){
        s3=s[i];
        m[s3]--;
        m2=m;
        for(int j=i+1;j<n-1;j++){
            int a=5;
            s4=s[j];
            m2[s4]--;
            if(s[i]==s[j]){continue;}
            a-=monmo(s[i]);
            a-=monmo(s[j]);
            s5=rgb[a];
            count+=m2[s5];
            if(j*2-i<=n)if(s[j*2-i]==rgb[a])count--;
        }
    }
    cout<<count;
}
