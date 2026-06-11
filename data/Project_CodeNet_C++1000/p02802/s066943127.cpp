#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<bool> a(n+1);
    vector<int>w(n+1,0);
    int acnt=0,wcnt=0;
    for(int i=0;i<m;i++){
        string s;
        int tmp;
        cin>>tmp>>s;
        if(s=="AC"){
            if(!a[tmp]){
                acnt++;
                wcnt+=w[tmp];
                a[tmp]=true;
            }
        }else{
            w[tmp]++;
        }
    }
    cout<<acnt<<" "<<wcnt<<endl;
    return 0;
}