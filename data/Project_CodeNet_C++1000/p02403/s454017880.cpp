#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int height,width;
    bool isOver = false;
    while(!isOver){
        cin>>height>>width;
        if(height ==0 && width == 0){
            isOver = true;
            break;
        }else{
            for(int i=0;i<height;i++){
                for(int j = 0;j<width;j++){
                cout<<'#';
                }
                cout<<endl;
            }
        }
        
        cout<<endl;
        
    
    }
	return 0;
}