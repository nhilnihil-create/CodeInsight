#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;
using Graph = vector<vector<int>>;
int main(){

int n;
cin>>n;
vector<string> s(n);

for(int i=0;i<n; i++){
    cin>>s[i];
}
sort(s.begin(),s.end());
int count=0;
for(int i=0;i<n-1;i++){
    if(s[i]==s[i+1]){
        count++;
    }
}
cout<<n-count<<endl;

}