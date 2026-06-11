#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n=s.size()+1;
    vector<int> a(n,-1);

//0の入力
    if(s.at(0)=='<') a.at(0)=0;
    for(int i=1; i<n-1; i++){
        if(s.at(i-1)!=s.at(i)) a.at(i)=0;
    }
    if(s.at(n-2)=='>') a.at(n-1)=0;

    int num=0;
    long long int ans=0;
    for(int i=0; i<n-1; i++){
        num=0;
        if(a.at(i)==0){
            while(s.at(i)=='<'){
                i++;
                num++;
                a.at(i)=num;
                if(i==n-1) break;
            }
        }
    }
/*    for(int i=0; i<n; i++){
        cout << a.at(i) << endl;
    }
    cout << endl;*/

    for(int i=n-1; i>0; i--){
        num=0;
        if(a.at(i)==0){
            while(s.at(i-1)=='>'){
                i--;
                num++;
                a.at(i)=max(a.at(i),num);
                if(i==0) break;
            }
        }
    }

    for(int i=0; i<n; i++){
        ans+=a.at(i);
        //cout << a.at(i) << endl;
    }
    cout << ans << endl;

}
