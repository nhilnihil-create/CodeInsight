#include <bits/stdc++.h>
using namespace std;

// int main(){
//     long long w,h,x,y;
//     cin >> w >> h >> x >> y;
//     long long yoko[2],tate[2];
//     yoko[0] = w*(h-y);
//     yoko[1] = w*y;
//     tate[0] = h*x;
//     tate[1] = h*(w-x);
//     cout << fixed << setprecision(6)<< double((max(min(yoko[0],yoko[1]),min(tate[0],tate[1]))));
//     cout << " ";
//     if (min(yoko[0],yoko[1])==min(tate[0],tate[1])){
//         cout << "1"<<endl;
//     }else{
//         cout << "0"<<endl;
//     }
//     return 0;
// }

int main(){
    long long w,h,x,y;
    cin >> w >> h >> x >> y;
    double res = (double)w*h/2;
    cout << fixed << setprecision(10) << res << " ";
    if(x*2==w&&y*2==h){
        cout << "1";
    }else{
        cout << "0";
    }
}