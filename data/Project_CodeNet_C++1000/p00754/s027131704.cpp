#include <iostream>

class CStack
{
public:
    CStack()
    {
        topIndex = 0;
    }
    ~CStack(){;}
    
    void push(char charactor)
    {
        if(topIndex < 100)  /* スタック可能数を超えてpushした場合、なにもしない */
        {
            stack[topIndex] = charactor;
            ++topIndex;
        }
    }
    char pop(void)
    {
        if(topIndex > 0)
        {
            --topIndex;
            return stack[topIndex];
        }
        return '\0';
    }
    char top(void)
    {
        return stack[topIndex-1];
    }
    bool enpty(void)
    {
        if(topIndex == 0)
        {
            return true;
        }
        return false;
    }
    
private:
    int topIndex;
    char stack[100];
};

/* 括弧の左右が対になっているか */
bool isMatchLeftRight(char left, char right)
{
    if((left == '(') && (right == ')'))
    {
        return true;
    }
    if((left == '[') && (right == ']'))
    {
        return true;
    }
    return false;
}

/* 1行がバランスしているか */
bool isBalance(char* line)
{
    bool result = true;
    CStack cStack;      /* スタック生成 */
    
    for(int index=0; index<100; ++index)
    {
        /* 行の最後か */
        if(line[index]=='.')
        {
            break;
        }
        
        if((line[index]=='(') || (line[index]=='['))
        {
            cStack.push(line[index]);    /* 左括弧をpush */
        }
        else
        {
            if((line[index]==')') || (line[index]==']'))
            {
                if(isMatchLeftRight(cStack.top(), line[index]))
                {
                    cStack.pop();        /* 直前の左括弧をpop */
                }
                else
                {
                    result = false;
                    break;
                }
            }
        }
    }
    
    if((result==true) && (cStack.enpty()))
    {
        result = true;
    }
    else
    {
        result = false;
    }
    return result;
}

int main(void)
{
    for(;;)
    {
        std::string sLine(100, '\0');
        getline(std::cin, sLine);   /* 1行取得 */
        
        if(sLine.size()>100) /* 100文字を超えていたら終了 */
        {
            break;
        }
        if(sLine[0]=='.')    /* データセットの最後なら処理終了 */
        {
            break;
        }
        
        /* 苦肉の策 */
        char line[100] = {'\0'};
        for(int index=0; index<sLine.size(); ++index)
        {
            line[index] = sLine[index];
        }

        /* 1行がバランスしているかチェック */
        bool result = true;
        result = isBalance(line);
        
        /* 1行の結果を出力 */
        if(result == true)
        {
            std::cout << "yes" << std::endl;
        }
        else
        {
            std::cout << "no" << std::endl;
        }
    }
    return 0;
}
