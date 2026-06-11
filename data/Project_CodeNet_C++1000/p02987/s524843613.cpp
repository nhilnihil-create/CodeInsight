#include<bits/stdc++.h> 

using namespace std;

int main()
{
    string a;
    cin >> a;
    int c = 0;
    if(a[1] == a[2]){
        if(a[3] == a[0]){
            c = 1;
            if(a[0] == a[1]){
                c = 0;
            }
        }
    }
    if(a[1] == a[0]){
        if(a[3] == a[2]){
            c = 1;
            if(a[0] == a[3]){
                c = 0;
            }
        }
    }
    if(a[1] == a[3]){
        if(a[2] == a[0]){
            c = 1;
            if(a[0] == a[3]){
                c = 0;
            }
        }
    }
    if(c == 1){
        cout <<"Yes"<<endl;
    }else{
        cout <<"No"<<endl;
    }

    return 0;
}
