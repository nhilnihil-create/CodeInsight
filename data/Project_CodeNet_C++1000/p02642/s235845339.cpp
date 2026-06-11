//
// Created by 10034 on 2020/7/29.
//

#include <iostream>
using namespace std;
int n,a[1000010];
int st[1000010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]),st[a[i]]++;
    int cnt=n;
    for(int i=1;i<=n;++i){
        for(int j=1;j*j<=a[i];++j){
            if(a[i]%j==0){
                int x=a[i]/j,y=j;
                if(st[x]&&(x!=a[i]||st[x]>1)){
                    cnt--;
                    break;
                }
                if(st[y]&&(y!=a[i]||st[y]>1)){
                    cnt--;
                    break;
                }
            }
        }
    }
    cout<<cnt<<endl;


    return 0;
}