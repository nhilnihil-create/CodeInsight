#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,M,flag=0;
    cin >> N >> M;
    vector<int> digid(N,10);
    for(int i=0;i<M;i++){
        int s,c;
        cin >> s >>c;
        if(s==1&&c==0) {
            digid.at(0)=0;
            flag++;
            break;
        }
        if(digid.at(s-1)==10||digid.at(s-1)==c){
        digid.at(s-1)=c;
        }else{
            flag++;
            break;
        }
    }
    
    if(N==1&&(digid.at(0)==0||digid.at(0)==10)){
        cout << 0;
    }else if(flag){
        cout << -1;
    }else{
        if(digid.at(0)==10) cout << 1;
        else cout << digid.at(0);
        for(int i=1;i<N;i++){
            if(digid.at(i)==10) cout << 0;
            else cout << digid.at(i);
        }
    }
}