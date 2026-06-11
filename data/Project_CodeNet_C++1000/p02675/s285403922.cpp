#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string s;
    cin>>s;
    int l=s.size()-1;
    if(s[l]=='2' || s[l]=='4' || s[l]=='5' || s[l]=='7' || s[l]=='9')
        cout<<"hon"<<endl;
    else if(s[l]=='0' || s[l]=='1' || s[l]=='6' || s[l]=='8')
        cout<<"pon"<<endl;
    else
        cout<<"bon"<<endl;
    return 0;
}
