#include <iostream>
#include <string>
#define ll long long
using namespace std;
int main(){
    ll score=0, x=1, h=1, n;
    int y, b=1;
    string a;
    cin >> a;
    cin >> n;
    y=a.size()-1;
    for(int i=1; i<=y; i++){
        if(a[i]==a[i-1]){
            h++;
        }
    }
    if(h==y+1){
        cout << h*n/2 << endl;
    }
    else{
        for(int i=1; i<=y; i++){
            if(a[i]==a[i-1]){
                b++;
            }
            else{
                score+=b/2;
                b=1;
            }
        }
        score+=b/2;
        while(a[x]==a[x-1]){
            x++;
        }
        if(x%2==1 && a[y]==a[0]){
            x++;
            while(a[y]==a[y-1]){
                y--;
                x++;
            }
            if(x%2==0){
                x=1;
            }
            else{
                x=0;
            }
        }
        else{
            x=0;
        }
        score*=n;
        score+=x*(n-1);
        cout << score << endl;
    }
    return 0;
}   