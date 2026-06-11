#include<bits/stdc++.h> 

using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a;
    int x[a];
    b = 0;
    for(int i = 0;i < a;i++){
        cin >> x[i];
    }
    for(int i = 1;i < (a-1);i++){
        c = 0;
        if(x[i] > x[i+1]){
            c++;
        }
        if(x[i] > x[i-1]){
            c++;
        }
        if(c == 1){
            b++;
        }
    }
    cout <<b<<endl;

    return 0;
}