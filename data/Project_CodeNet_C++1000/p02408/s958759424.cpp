#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	bool cardList[4][13];
    for(int i=0;i<4;i++){
        for(int j =0;j<13;j++){
            cardList[i][j] = false;
        }
    }
    
    int cardCount;
    cin>>cardCount;
    for(int k = 0;k<cardCount;k++){
        char cardType;
        int line = 0;
        int number;
        cin>>cardType>>number;
        number -= 1;
        switch(cardType){
            case 'S':
            line = 0;
            break;
            case 'H':
            line = 1;
            break;
            case 'C':
            line = 2;
            break;
            case 'D':
            line = 3;
            break;
        }
        
        cardList[line][number] = true;
    }
    
    for(int i=0;i<4;i++){
        for(int j =0;j<13;j++){
            char out;
            int number;
            if(cardList[i][j]==false){
                switch(i){
                    case 0:
                    out = 'S';
                    break;
                    case 1:
                    out = 'H';
                    break;
                    case 2:
                    out = 'C';
                    break;
                    case 3:
                    out = 'D';
                    break;
                }
                number = j+1;
                cout<<out<<' '<<number<<endl;
            }
        }
    }
    
	return 0;
}