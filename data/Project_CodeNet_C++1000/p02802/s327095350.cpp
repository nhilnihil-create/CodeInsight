#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m, a1=0, a2=0; 
    cin >> n >> m;
    vector<bool>ac(n);
    vector<int>wa(n);
    for(int i=0; i<n; i++){
        wa[i]=0;
        ac[i]=0;
    } 
    int c;
    string s;
    for(int i=0; i<m; i++){
        cin >> c >> s;
        if(s[0]=='W') wa[c]++;
        else{
            if(!ac[c]){
                ac[c]=1;
                a1++;
                a2 += wa[c];
            }
        } 
    }
    printf("%d %d\n",a1,a2);
    return 0;
}