#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<math.h>
using namespace std;
#define mod (1000000000+7)
#define N (10007)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P > T;

int h,w;
bool finish(){
    return (h==0)&&(w==0);
}

int main(void){
    while(true){
        cin>>h>>w;
        if(finish())break;
        int ans1 = 0,ans2 = 0;
        int min_=0;
        int base = h*h+w*w;
        vector<P>p;
        for(int i=1;i<=150;i++){
            for(int j=i+1;j<=150;j++){
                if(i*i+j*j==base){
                    if(h<i)p.push_back(P(i,j));
                }
            }
        }
        if(p.size()>0){
            for(int i=0;i<(int)p.size();i++){
                if(ans1 == 0 && ans2 == 0){
                    ans1 = p[i].first;
                    ans2 = p[i].second;
                }
                else{
                    if(p[i].first<ans1){
                        ans1 = p[i].first;
                        ans2 = p[i].second;
                    }
                }
            }
            cout<<ans1<<" "<<ans2<<endl;
        }
        else{
            for(int i=1;i<=150;i++){
                for(int j=i+1;j<=150;j++){
                    if(i*i+j*j>base){
                        if(min_==0)min_=i*i+j*j;
                        else min_ = min(min_,i*i+j*j);
                    }
                }
            }
            for(int i=1;i<=150;i++){
                for(int j=i+1;j<=150;j++){
                    if(i*i+j*j==min_){
                        if(ans1 == 0 && ans2 == 0){
                            ans1 = i;
                            ans2 = j;
                        }
                        else{
                            if(i<ans1){
                                ans1 = i;
                                ans2 = j;
                            }
                        }
                    }
                }
            }
            cout<<ans1<<" "<<ans2<<endl;
        }
    }
    return 0;
}
