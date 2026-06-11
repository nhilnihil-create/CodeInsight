#include <iostream>
#include <string>

using namespace std;
int main(void){
    // Your code here!
    int bNum[6];
    int aNum[6];
    aNum[6] = 1;
    
    int leng = 0;
    string str1, str2;
    
    for(int i=0; i<6; i++){
        cin >> bNum[i];
        aNum[i] =bNum[i];
    }
    
    cin >> str1;
    leng = str1.length();
    
    for(int i=0; i<leng; i++){
        if(str1[i]=='S'){
            aNum[0] = bNum[4];
            aNum[1] = bNum[0];
            aNum[5] = bNum[1];
            aNum[4] = bNum[5];
            
            bNum[4] = aNum[4];
            bNum[0] = aNum[0];
            bNum[5] = aNum[5];
            bNum[1] = aNum[1];
        }else if(str1[i]=='N'){
            aNum[0] = bNum[1];
            aNum[1] = bNum[5];
            aNum[5] = bNum[4];
            aNum[4] = bNum[0];
            
            bNum[0] = aNum[0];
            bNum[1] = aNum[1];
            bNum[4] = aNum[4];
            bNum[5] = aNum[5];
        }else if(str1[i]=='W'){
            aNum[0] = bNum[2];
            aNum[3] = bNum[0];
            aNum[2] = bNum[5];
            aNum[5] = bNum[3];
            
            bNum[0] = aNum[0];
            bNum[3] = aNum[3];
            bNum[2] = aNum[2];
            bNum[5] = aNum[5];
        }else if(str1[i]=='E'){
            aNum[2] = bNum[0];
            aNum[0] = bNum[3];
            aNum[5] = bNum[2];
            aNum[3] = bNum[5];
            
            bNum[2] = aNum[2];
            bNum[0] = aNum[0];
            bNum[5] = aNum[5];
            bNum[3] = aNum[3];
        }
    }
    
    cout << bNum[0] << endl;
    
}

