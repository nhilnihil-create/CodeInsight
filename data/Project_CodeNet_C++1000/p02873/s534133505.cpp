#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    std::deque<string> deq;
    string tmp="";
    for (int i=0;i<s.size();i++) {
        tmp+=s[i];
        if (i!=s.size()-1) {
            if (s[i]=='>'&&s[i+1]=='<') {
                deq.emplace_back(tmp);
                tmp="";
            }
        } else {
            deq.emplace_back(tmp);
        }
    }
    long long int sum=0;
    for (int i=0;i<deq.size();i++) {
        string mark=deq[i];
        long long int inc=0,dec=0;
        for (int j=0;j<mark.size();j++) {
            if (mark[j]=='<') {
                inc++;
            } else {
                dec++;
            }
        }
        if (inc>dec) {
            dec--;
            if (dec>=0&&dec%2==0) {
                sum+=(dec+1)*(dec/2);
            } else {
                sum+=(dec+1)*(dec/2)+(dec+1)/2;
            }
            if (inc>=0&&inc%2==0) {
                sum+=(inc+1)*(inc/2);
            } else {
                sum+=(inc+1)*(inc/2)+(inc+1)/2;
            }
        } else if (inc<dec) {
            inc--;
            if (dec>=0&&dec%2==0) {
                sum+=(dec+1)*(dec/2);
            } else {
                sum+=(dec+1)*(dec/2)+(dec+1)/2;
            }
            if (inc>=0&&inc%2==0) {
                sum+=(inc+1)*(inc/2);
            } else {
                sum+=(inc+1)*(inc/2)+(inc+1)/2;
            }
        } else {
            if (dec>=0&&dec%2==0) {
                sum+=(dec+1)*(dec/2);
            } else {
                sum+=(dec+1)*(dec/2)+(dec+1)/2;
            }
            if (inc>=0&&inc%2==0) {
                sum+=(inc+1)*(inc/2);
            } else {
                sum+=(inc+1)*(inc/2)+(inc+1)/2;
            }
            sum-=inc;
        }
    }
    cout<<sum<<endl;
}