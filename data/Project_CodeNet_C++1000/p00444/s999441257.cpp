#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int nyuuryoku[5];
    int oturi[5];
    int maisuu[5];
    int data;
    
    for(int i=0;i<5;i++){
        maisuu[i]=0;
    }
    
    for(int i=0;;i++){
        cin >> nyuuryoku[i];
        if(nyuuryoku[i]==0){
            data=i;
            break;
        }
    }
    
    
    for(int i=0;i<data;i++){
        oturi[i]=1000-nyuuryoku[i];
    }
    
    
    for(int i=0;i<data;i++){
        
        for(;;){  //500???
            if(oturi[i]<500){
                break;
            }
            oturi[i]=oturi[i]-500;
            maisuu[i]++;
        }
        
        for(;;){  //100???
            if(oturi[i]<100){
                break;
            }
            oturi[i]=oturi[i]-100;
            maisuu[i]++;
        }
        
        
        for(;;){  //50???
            if(oturi[i]<50){
                break;
            }
            oturi[i]=oturi[i]-50;
            maisuu[i]++;
        }
        
        
        for(;;){  //10???
            if(oturi[i]<10){
                break;
            }
            oturi[i]=oturi[i]-10;
            maisuu[i]++;
        }
        
        
        for(;;){  //5???
            if(oturi[i]<5){
                break;
            }
            oturi[i]=oturi[i]-5;
            maisuu[i]++;
        }
        
        
        for(;;){  //1???
            if(oturi[i]<1){
                break;
            }
            oturi[i]=oturi[i]-1;
            maisuu[i]++;
        }
        
    }
    
    
    
    for(int i=0;i<data;i++){
        cout << maisuu[i] << endl;
    }
    
    
    return 0;
}