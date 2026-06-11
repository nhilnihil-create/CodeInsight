#include <iostream>

using namespace std;

int isNum(char);
int power(int, int);

int main(){
        int p = 0, i = 0;    //p: buffer????????????????????????, i:formula????????????????????????
        int count = 0;    //??°????????????????????°
        int tmp;
        int val;
        string formula;
        int buffer[100] = {0};

        getline(cin, formula);
        while(formula[i] != '\0'){
                if((val = isNum(formula[i]))){
                        buffer[p] = (val < 0)? 0:val;    //??????p????????????????????°???????????\
                        p = p + 1;    //?¬?????????????
                        ++count;
                }else{
                        switch (formula[i]) {
                                case ' ':
                                        if(count){    //??´??????buffer?????°??????????????????????????´???,?????£?¶?????????°????????£????????°???????????£
                                                tmp = p - count;
                                                buffer[tmp] *= power(10, --count);
                                                for(; count > 0; count--){
                                                        buffer[tmp] += buffer[p - count] * power(10, count-1);
                                                }
                                                p = tmp + 1;
                                                count = 0;
                                        }
                                        break;
                                case '+':
                                        buffer[p - 2] += buffer[p - 1];
                                        p = p - 1;
                                        break;
                                case '-':
                                        buffer[p - 2] -= buffer[p - 1];
                                        p = p - 1;
                                        break;
                                case '*':
                                        buffer[p - 2] *= buffer[p - 1];
                                        p = p - 1;
                                        break;
                        }
                }
                i++;
        }

        cout<<buffer[0]<<endl;

}

int isNum(char a){
        int judge;
        char numlist[10] = {'0','1','2','3','4','5','6','7','8','9'};

        for(judge = 0; judge < 10; judge++){
                if(a == numlist[judge]) break;
        }

        if(judge == 10){
                judge = 0;
        }else if(judge == 0){
                judge = -1;
        }

        return judge;
}

int power(int x, int n){
        int result = 1;

        for(; n >0; n--){
                result *= x;
        }
        return result;
}