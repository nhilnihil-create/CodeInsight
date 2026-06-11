#include <stdio.h>

#define MAX_LSIZE 100  // 一行の最大の長さ 
char buff[MAX_LSIZE+2];  // 一行の文字列を格納する配列     
// 行末の改行文字、NULL 文字も格納される 
char stack[MAX_LSIZE];  // スタック 
int sp;    // スタックポインタ 
 
int main() {   
    char c;  // 処理する文字を入れる変数   
    int match; // 括弧のバランス状況を表す   // 1 -> バランス,  0 -> 非バランス, -1 -> まだ不明   
    int i;   
    while(1){     
        fgets(buff, MAX_LSIZE+2, stdin); // 標準入力より配列 buff に１行読み込む     
        if(buff[0] == '.') break; // 先頭の文字が '.' なら終了     
        match = -1;  // バランス状況はまだ不明     
        sp = 0;   // stack pointer sp を初期化     
        for(i=0; ; i++){ // 文字列の先頭から順に１文字ずつ以下の処理を行う       
            c = buff[i];  // c = 処理対象の文字       
            switch(c){       
                case '(':       
                case '[':  
                        stack[sp++] = c; 
                        break;  // stack に 左括弧 を入れる       
                case ')': // stack が空か、 // stack から取り出した文字が '(' でなければバランスしていない  
                    if(sp==0) match=0;  
                    else if(stack[--sp] != '(') match = 0;  
                    break;       
                case ']': // stack が空か、 // stack から取り出した文字が '[' でなければバランスしていない  
                    if(sp==0) match=0;  
                    else if(stack[--sp] != '[') match = 0;  
                    break;       
                case '.': // stack が空ならバランス、そうでなければ非バランス  
                    if(sp==0) match=1;  
                    else match=0;       
            }       
            if(match != -1) break; // 結果が判明したので終了    
        } 
        if(match) printf("yes\n"); // 結果を出力     
        else printf("no\n");   
    } 
}
