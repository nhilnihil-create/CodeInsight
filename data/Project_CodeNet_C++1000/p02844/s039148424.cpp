#include<bits/stdc++.h>
using namespace std;

//mitsuisumitomo2019-d.cppだとなぜか変数の色分けがうまくされない
int main(){
    int n;
    cin>>n;

    //sの入力は分割されていない(数字の間に空白がない)ので配列ではなくstringを使う
    string s;
    cin>>s;

    int cnt=0;
    
    for(int i=0;i<1000;i++){
        int v[3]={i/100,(i/10)%10,i%10};
        
        int f=0;
        for(int j=0;j<n;j++){
            if(s[j]==v[f]+'0') f++;
            if(f==3) break;
        }
        if(f==3) cnt++;
    }

    cout<<cnt<<endl;
}