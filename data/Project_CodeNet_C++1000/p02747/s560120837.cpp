#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    int flag=0,h=0;
    if (s.size()==1) {
        flag=1;
    } else {
        for (int i=0;i<s.size();i++) {
            if (s[i]=='h') {
                if (h==0) {
                    h=1;
                } else {
                    flag=1;
                    break;
                }
            } else if (s[i]=='i') {
                if (h==1) {
                    h=0;
                } else {
                    flag=1;
                    break;
                }
            } else {
                flag=1;
                break;
            }
        }
    }
    if (flag==0&&h==0) {
        cout<<"Yes"<<endl;
    } else {
        cout<<"No"<<endl;
    }
}
