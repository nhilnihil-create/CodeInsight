#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    long long int k;
    cin >> s >> k;
    long long int n=s.size();
    long long int ans;
    bool all=true,same=false;
    if(s[0]==s[s.size()-1])same=true;

    for(long long int i=0; i<n-1; i++){
        if(s[i]!=s[i+1]){
            all=false;
            //cout << "OK!" << endl;
            break;
        }
    }

    long long int cnt_x=1,x=0;
    long long int cnt_y=1,y=0;
    string t=s+s;

    for(long long int i=0; i<n-1; i++){
        if(s[i]==s[i+1]){
            cnt_x++;
            if(i==n-2)x+=cnt_x/2;
        }
        else{
            x+=cnt_x/2;
            cnt_x=1;
        }
    }
    for(long long int i=0; i<2*n-1; i++){
        if(t[i]==t[i+1]){
            cnt_y++;
            if(i==2*n-2)y+=cnt_y/2;
        }
        else{
            y+=cnt_y/2;
            cnt_y=1;
        }
    }

    if(all==true){
        switch (k%2){
        case 0:
            cout << y*(k/2);
            break;
        case 1:
            cout << y*(k/2)+x;
        default:
            break;
        }
    }
    else if(same==true)cout << x+(y-x)*(k-1);
    else cout << x*k;
    cout << endl;
}
