#include <bits/stdc++.h>
using namespace std;
int main (){
    long long int t1,t2,a1,a2,b1,b2,e1,e2,ans=0;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    
    e1=(a1-b1)*t1;
    e2=(a2-b2)*t2;

    if(e1+e2==0){
        cout << "infinity" << endl;
        return 0;
    }
    if(e1>0 && e2>0){
        cout << 0 << endl;
        return 0;
    }
    if(e1 < 0 && e2 < 0){
        cout << 0 << endl;
        return 0;
    }
    if(e1 > 0 && e2 < 0 && e1+e2>0){
        cout << 0 << endl;
        return 0;
    }    
    if(e1 < 0 && e2 > 0 && e1+e2<0){
        cout << 0 << endl;
        return 0;
    }

    if(e1 > 0 && e2 < 0 && e1+e2<0){
        long long int d=(-1)*(e1+e2);
        if(e1%d==0){
            cout << 2*(e1/d) << endl;
        }else{
            cout << 2*(e1/d)+1 << endl;
        }
        return 0;
    }
    if(e1 < 0 && e2 > 0 && e1+e2>0){
        long long int d=e1+e2,s=(-1)*e1;
        if(s%d==0){
            cout << 2*(s/d) << endl;
        }else{
            cout << 2*(s/d)+1 << endl;
        }
        return 0;
    }
}