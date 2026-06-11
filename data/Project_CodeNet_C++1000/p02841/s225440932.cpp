#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int lastDay[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    int a,b;
    cin>>a>>b;
    cout<<(lastDay[a]==b)<<endl;

    return 0;
}