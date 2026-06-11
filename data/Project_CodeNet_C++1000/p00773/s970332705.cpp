
#include <iostream>

using namespace std;
int fmax(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int x,y;
int tax(int n){
    int p = 0;
    for(int i = 1 ; i < 1000 ; i++){
        if(i*(100+x)/100 == n){
            p = i;
            break;
        }
    }
    return p*(100+y)/100;
}

int main(){
    int s;
    while(cin >> x >> y >> s,(x|y|s)){
        int max = 0;
        for(int i = 1 ; i <= s/2 ; i++){
            max =fmax(max,tax(i)+tax(s-i));
        }
        cout << max << endl;
    }
    return 0;
}