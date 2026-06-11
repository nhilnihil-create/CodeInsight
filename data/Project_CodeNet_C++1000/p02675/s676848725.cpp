#include <bits/stdc++.h>
#define NAME "INPUT"
using namespace std;
ifstream fi (NAME".inp");
ofstream fo (NAME".out");
int main(){
     int n;
     cin>>n;
     int x=n%10;
     set<int> a={2,4,5,7,9};
     set<int> b={0,1,6,8};
        if(a.find(x)!=a.end())
            cout<<"hon";
        if(b.find(x)!=b.end())
            cout<<"pon";
        if(x==3) cout<<"bon";
}



