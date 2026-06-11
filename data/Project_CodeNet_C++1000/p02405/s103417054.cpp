#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int height,width;
    char dot = '.';
    char sharp = '#';
    char printChar;
    bool isOver = false;
    while(!isOver){
        cin>>height>>width;
        if(height ==0 && width == 0){
            isOver = true;
            break;
        }else{
            //add frame ops
            for(int i=0;i<height;i++){
                for(int j = 0;j<width;j++){
                    printChar = dot;
                    if((i+j)%2==0){
                        printChar = sharp;
                    }
                    cout<<printChar;
                    
                }
                cout<<endl;
            }
        }
        
        cout<<endl;
        
    
    }
	return 0;
}