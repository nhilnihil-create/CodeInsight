#include <iostream>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
int main(void){
set<long long> s;
int n;
cin>>n;

for(int i=0;i<n;i++){
    long long a;
    cin>>a;
    if(s.find(a)!=s.end())
        {
            cout<<"NO";
            return 0;
        }
    s.insert(a);
}
cout<<"YES";
}

