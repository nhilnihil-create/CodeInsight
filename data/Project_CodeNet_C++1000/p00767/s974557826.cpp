#include <iostream>
using namespace std;

bool isSmaller(int ah,int aw,int bh,int bw){
    if((bh*bh+bw*bw)<(ah*ah+aw*aw)){
        return true;
    }else{
        if((bh*bh+bw*bw)==(ah*ah+aw*aw)&&bh<ah){
            return true;
        }
    }
    return false;
}

int main() {
    int h,w;

    while(true){
        cin>>h>>w;
        if(h==0 && w==0){
            break;
        }

        int answ=200,ansh=200;

        for(int i=1;i<151;i++){
            for(int j=i+1;j<151;j++){
                if(isSmaller(i,j,h,w)){
                    if(isSmaller(ansh,answ,i,j)){
                        ansh=i;
                        answ=j;
                    }
                }
            }
        }
        cout<<ansh<<" "<<answ<<endl;
    }
    return 0;
}