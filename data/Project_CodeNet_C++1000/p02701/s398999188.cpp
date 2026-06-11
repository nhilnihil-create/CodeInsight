#include <bits/stdc++.h>
using namespace std;


int main() {
int n;
cin>>n;
    set<string> s;

for(int i=0;i<n;i++)
{
string a;
cin>>a;
s.insert(a);

}
int ans=s.size();
cout<<ans<<endl;
}