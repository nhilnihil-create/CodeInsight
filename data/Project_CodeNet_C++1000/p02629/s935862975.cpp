#include<bits/stdc++.h>
using namespace std;
int main()
{long long n;
cin>>n;
vector <char> c(26);
for(int i =1;i<26;i++)
c[i] = 'a'+i-1;
c[0] = 'z';
// for(auto i:)
string s;
while(n>0)
{    n--;
    int temp = n%26;
    s=(char)(temp+'a')+s;
    n/=(long long)26;
//    cout<<c[temp];

}
cout<<s<<endl;
    return 0;
}