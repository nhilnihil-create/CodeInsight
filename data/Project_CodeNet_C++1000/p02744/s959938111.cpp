#include <bits/stdc++.h>
using namespace std;
int main(){

  int N;
  cin >> N;
  char alf[]={'z','a','b','c','d','e','f','g','h','i','j'};

  int combi = pow(2,20);
  vector<vector<string>> data(combi,vector<string>(10));
  data.at(0).at(0) = alf[1];
  
  int input_num,output_num,str_count;
  
  for (int i_clm=1; i_clm<N; i_clm++){

    if(i_clm==1){
      output_num = 0;
      input_num = 1;
    }else{
      input_num = output_num;
      output_num = 0;
    }
        
    for(int i_row_b=0; i_row_b < input_num; i_row_b++){
      
      //元となる文字列から文字の種類を取得
      str_count=0;
      for(int i_len=0; i_len < strlen(alf); i_len++){
        for(int ii_len=0; ii_len < data.at(i_row_b).at(i_clm-1).length(); ii_len++){
          if (alf[i_len] == data.at(i_row_b).at(i_clm-1)[ii_len]){
            str_count++;
            break;
          }
        }
      }

      //文字列を出力 
      for(int i_row_a=0; i_row_a < str_count+1; i_row_a++){
        data.at(output_num).at(i_clm) = data.at(i_row_b).at(i_clm-1) + alf[i_row_a+1];
        output_num++;
      }
    }  
  
  }
    
  for (int i=0; data.at(i).at(N-1)!="";i++){
    cout << data.at(i).at(N-1) << endl;  
  }

}
