#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int base = 400;
    int answer =8;
    for(int g=0;g<8;g++)
    {
        base = base + 200; 
        if(n<base)
        {
            break;
        }
        answer --;
    }
    cout<<answer<<endl;
    //system("PAUSE");



}