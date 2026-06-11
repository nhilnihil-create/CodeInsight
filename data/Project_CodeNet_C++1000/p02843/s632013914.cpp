#include <bits/stdc++.h>
using namespace std;
int main(void){
    int x,flag=0;
    cin>>x;
    std::deque<int> deq{105,104,103,102,101,100};
    for (int i=0;i<6;i++) {
        if (x%deq[i]==0) {
            cout<<1<<endl;
            flag=1;
            break;
        } else {
            int tmp=x/deq[i];
            for (int j=tmp;j>=1;j--) {
                for (int k=i+1;k<6;k++) {
                    if ((x-deq[i]*j)%deq[k]==0) {
                        cout<<1<<endl;
                        flag=1;
                        break;
                    }
                }
                if (flag==1) {
                    break;
                }
            }
        }
        if (flag==1) {
            break;
        }
    }
    if (flag==0) {
        cout<<0<<endl;
    }
}