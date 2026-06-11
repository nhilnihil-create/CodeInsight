#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int h,w,a,b;

    cin >> h >> w >> a >> b;

    string str1,str2;
    if(a == 0){
        str1 = string(w-a,'1');
        str2 = string(w-a,'0');
    }else{
        str1 = string(a,'0')+string(w-a,'1');
        str2 = string(a,'1')+string(w-a,'0');
    }

    
    for(int i = 0; i < b; i++){
        
        cout << str1 << endl;
    }
    for(int i = b; i < h; i++){
        
        cout << str2 << endl;
    }
}