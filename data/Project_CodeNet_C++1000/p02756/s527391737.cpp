#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>
#include<bitset>
#include<string>
#include<utility>
#include<algorithm>
#include<queue>

using namespace std;

int main(){
    string s;
    int q,nfront=0,ntail=0;
    bool isrev=false;
    vector<char> front(200000);
    vector<char> tail(200000);

    cin >> s >> q;
    int t,f;
    char c;
    for(int i=0;i<q;i++){
        cin >> t;
        if(t==1){
            isrev= (!isrev);
        }else{
            cin >> f >>  c;
            if(((isrev==false)&&f==1) || ((isrev==true)&&f==2)){
                front.at(nfront)=c;
                nfront++;
            }else{
                tail.at(ntail)=c;
                ntail++;
            }
        }
    }
    if(isrev){
        reverse(s.begin(),s.end());
        for(int i=ntail-1;i>=0;i--){
            cout << tail.at(i);
        }
        cout << s;
        for(int i=0;i<nfront;i++){
            cout << front.at(i);
        }
        cout << endl;
    }else{
        for(int i=nfront-1;i>=0;i--){
            cout << front.at(i);
        }
        cout << s;
        for(int i=0;i<ntail;i++){
            cout << tail.at(i);
        }
        cout << endl;
    }

    return 0;
}