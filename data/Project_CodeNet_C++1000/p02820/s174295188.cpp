#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,k,r,s,p;
    cin>>n>>k>>r>>s>>p;
    string t;
    cin>>t;
    std::deque<char> tmp(n,'\0');
    int sum=0;
    for (int i=0;i<n;i++) {
        if (i<k) {
            if (t[i]=='r') {
                sum+=p;
                tmp[i]='p';
            } else if (t[i]=='s') {
                sum+=r;
                tmp[i]='r';
            } else {
                sum+=s;
                tmp[i]='s';
            }
        } else {
            if (t[i]=='r'&&tmp[i-k]=='p') {
                if (i+k<n) {
                    if (t[i+k]=='r') {
                        tmp[i]='s';
                    } else if (t[i+k]=='p') {
                        tmp[i]='r';
                    } else if (t[i+k]=='s') {
                        tmp[i]='s';
                    }
                } else {
                    tmp[i]='s';
                }
            } else if (t[i]=='s'&&tmp[i-k]=='r') {
                if (i+k<n) {
                    if (t[i+k]=='r') {
                        tmp[i]='s';
                    } else if (t[i+k]=='p') {
                        tmp[i]='p';
                    } else if (t[i+k]=='s') {
                        tmp[i]='p';
                    }
                } else {
                    tmp[i]='p';
                }
            } else if (t[i]=='p'&&tmp[i-k]=='s') {
                if (i+k<n) {
                    if (t[i+k]=='r') {
                        tmp[i]='r';
                    } else if (t[i+k]=='p') {
                        tmp[i]='r';
                    } else if (t[i+k]=='s') {
                        tmp[i]='p';
                    }
                } else {
                    tmp[i]='r';
                }
            } else {
                if (t[i]=='r') {
                    sum+=p;
                    tmp[i]='p';
                } else if (t[i]=='s') {
                    sum+=r;
                    tmp[i]='r';
                } else {
                    sum+=s;
                    tmp[i]='s';
                }
            }
        }
    }
    cout<<sum<<endl;
}