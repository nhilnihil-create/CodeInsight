#include <iostream>
#include <string>
using namespace std;
int diff(string &a, string &b)
{
    int ans=0;
    for (int i = 0; i <2*100000 ; ++i) {
        if(int(a[i])>=int ('a')&&int (a[i])<=int ('z')) { if (a[i] != b[i])ans++; }
        else
            break;
    }
    return ans;
}
int main() {
string a,b;
cin>>a>>b;
cout<<diff(a,b)<<endl;
}

