#include <bits/stdc++.h>
using namespace std;

int main() {
int64_t a,c,d;
c=0;
d=0;
char b;
cin>>a;
vector<char> vec(3);
for(int64_t i=0;i<4;i++){
cin>>b;
if(b!='.'){vec.at(d)=b;
           d++;}
}
c=(int64_t)((vec.at(0)-'0')*100+(vec.at(1)-'0')*10+vec.at(2)-'0');
cout<<a*c/100<<endl;
} 
