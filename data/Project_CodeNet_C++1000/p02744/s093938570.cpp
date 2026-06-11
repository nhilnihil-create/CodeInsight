#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char s[12];
int n;
void dfs(int indx,char c){
    //cout << indx << endl;
    if(indx==n){
    //    cout << indx <<endl;
        printf("%s\n",s);
        //cout <<s <<endl;
        return ;
    }
    for(char i='a';i<=c;i++){
        s[indx]=i;
        dfs(indx+1,max((char)(i+1),c));
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    cin >> n;
    s[0]='a';
    dfs(0,'a');
    return 0;
}
