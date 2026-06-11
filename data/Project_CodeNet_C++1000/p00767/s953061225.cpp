#include <bits/stdc++.h>
using namespace std;
int main(void){
    int h,w;
    while (cin>>h>>w) {
        if (h==0&&w==0) {
            break;
        } else {
            int sum=0;
            int min=100000;
            int min_h=100000;
            int ans_h,ans_w;
            sum+=h*h+w*w;
            for (int i=1;i<150;i++) {
                for (int j=i+1;j<=150;j++) {
                    if (sum<i*i+j*j) {
                        if (min>i*i+j*j) {
                            min=i*i+j*j;
                            ans_h=i;
                            ans_w=j;
                        }
                    } else if ( (sum==i*i+j*j)&&(i!=h&&j!=w) ) {
                        if (min_h>i&&i>h) {
                            min=i*i+j*j;
                            min_h=i;
                            ans_h=i;
                            ans_w=j;
                        }
                    }
                }
            }
            cout<<ans_h<<" "<<ans_w<<endl;
        }
    }
}

