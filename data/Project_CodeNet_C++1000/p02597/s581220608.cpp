#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int start=0,end=n-1,count=0;
    while (1) {
        if (s[end]=='R') {
            while (1) {
                if (s[start]=='W') {
                    swap(s[start],s[end]);
                    count++;
                    start++;
                    break;
                } else {
                    start++;
                }
                if (start==n+1||start>=end) {
                    break;
                }
            }
            end--;
        } else {
            end--;
        }
        if (start>=end) {
            break;
        }
    }
    cout<<count<<endl;
}